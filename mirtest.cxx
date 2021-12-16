#include <vtkm/cont/DataSet.h>
#include <vtkm/cont/Timer.h>

#include <vtkm/filter/MIRFilter.h>

#include <vtkm/io/VTKDataSetWriter.h>

#include <boost/program_options.hpp>

#include "makedata.h"

int omp_thread_count() {
    int n = 0;
    #pragma omp parallel reduction(+:n)
    n += 1;
    return n;
}

enum class Device
{
  CPU = 0,
  GPU
};

int main(int argc, char **argv) {

  vtkm::cont::SetStderrLogLevel(vtkm::cont::LogLevel::Off);
  namespace options = boost::program_options;
  options::options_description desc("Options");

  desc.add_options()("data",    options::value<std::string>()->required(), "Path to dataset")
                    ("device",  options::value<int>(),                     "Execution device");

  options::variables_map vm;
  options::store(options::parse_command_line(argc, argv, desc), vm);
  options::notify(vm);

  std::string dataset(vm["data"].as<std::string>());
  std::cerr << "Reading data from : " << dataset << std::endl;
  Device device  = static_cast<Device>(vm["device"].as<int>());

  vtkm::filter::MIRFilter mir;
  mir.SetIDWholeSetName("scatter_ids");
  mir.SetPositionCellSetName("scatter_pos");
  mir.SetLengthCellSetName("scatter_len");
  mir.SetVFWholeSetName("scatter_vfs");

  mir.SetErrorScaling(vtkm::Float64(0.2));
  mir.SetScalingDecay(vtkm::Float64(1.0));
  mir.SetMaxIterations(vtkm::IdComponent(0)); // =0 -> No iterations..
  mir.SetMaxPercentError(vtkm::Float64(
    0.00001)); // Only useful for iterations >= 1, will stop iterating if total % error for entire mesh is less than this value
  // Note it is mathematically impossible to obtain 0% error outside of VERY special cases (neglecting float error)

  if(device == Device::CPU)
  {
    auto numThreads = omp_thread_count();
    std::cout << "Threads : " << numThreads << std::endl;
    auto device = vtkm::cont::DeviceAdapterTagOpenMP{};
    vtkm::cont::ScopedRuntimeDeviceTracker tracker(device);

    vtkm::cont::DataSet ds = data::MakeData(dataset);
    std::cerr << "Input cells : " << ds.GetNumberOfCells() << std::endl;
    std::cerr << "Input points : " << ds.GetNumberOfPoints() << std::endl;

    vtkm::cont::Timer timer;
    timer.Start();

    vtkm::cont::DataSet ds_from_mir = mir.Execute(ds);

    timer.Stop();

    std::cerr << "Finished in : " << timer.GetElapsedTime() << std::endl;
    std::cerr << "Output cells : " << ds_from_mir.GetNumberOfCells() << std::endl;
    std::cerr << "Output points : " << ds_from_mir.GetNumberOfPoints() << std::endl;

  }
  else
  {
    auto device = vtkm::cont::DeviceAdapterTagCuda{};
    vtkm::cont::ScopedRuntimeDeviceTracker tracker(device);
    vtkm::cont::DataSet ds = data::MakeData(dataset);
    std::cerr << "Input cells : " << ds.GetNumberOfCells() << std::endl;
    std::cerr << "Input points : " << ds.GetNumberOfPoints() << std::endl;

    vtkm::cont::Timer timer;
    timer.Start();

    vtkm::cont::DataSet ds_from_mir = mir.Execute(ds);

    timer.Stop();

    std::cerr << "Finished in : " << timer.GetElapsedTime() << std::endl;
    std::cerr << "Output cells : " << ds_from_mir.GetNumberOfCells() << std::endl;
    std::cerr << "Output points : " << ds_from_mir.GetNumberOfPoints() << std::endl;
  }

  return 0;
}
