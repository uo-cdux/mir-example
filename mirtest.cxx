#include <vtkm/cont/DataSet.h>

#include <vtkm/filter/MIRFilter.h>

#include <vtkm/io/VTKDataSetWriter.h>

#include "makedata.h"

int main(int argc, char** argv)
{
  vtkm::cont::DataSet ds = data::MakeData();
  std::cerr << "Cells : " << ds.GetNumberOfCells() << std::endl;
  std::cerr << "Points : " << ds.GetNumberOfPoints() << std::endl;

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
  VTKM_LOG_S(vtkm::cont::LogLevel::Warn, "Before executing filter");

  vtkm::cont::DataSet ds_from_mir = mir.Execute(ds);

  VTKM_LOG_S(vtkm::cont::LogLevel::Warn, "After executing filter");

  std::cerr << "Cells : " << ds_from_mir.GetNumberOfCells() << std::endl;
  std::cerr << "Points : " << ds_from_mir.GetNumberOfPoints() << std::endl;

  vtkm::io::VTKDataSetWriter writer("output.vtk");
  writer.WriteDataSet(ds_from_mir);

  return 0;
}
