#ifndef MAKE_MIR_DATA
#define MAKE_MIR_DATA

#include <vector>
#include <vtkm/Types.h>

#include <vtkm/cont/Algorithm.h>
#include <vtkm/cont/DataSetBuilderRectilinear.h>
#include <vtkm/cont/Invoker.h>

#include <vtkm/io/VTKDataSetReader.h>

#include <vtkm/worklet/WorkletMapField.h>

namespace data {

std::vector<vtkm::FloatDefault> XCoords{
    0,    0.04, 0.08, 0.12, 0.16, 0.2,  0.24, 0.28, 0.32,
    0.36, 0.4,  0.44, 0.48, 0.52, 0.56, 0.6,  0.64, 0.68,
    0.72, 0.76, 0.8,  0.84, 0.88, 0.92, 0.96, 1};

std::vector<vtkm::FloatDefault> YCoords{
    0,    0.04, 0.08, 0.12, 0.16, 0.2,  0.24, 0.28, 0.32,
    0.36, 0.4,  0.44, 0.48, 0.52, 0.56, 0.6,  0.64, 0.68,
    0.72, 0.76, 0.8,  0.84, 0.88, 0.92, 0.96, 1};

std::vector<vtkm::FloatDefault> BackVec{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};

std::vector<vtkm::FloatDefault> CirAVec{
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        1,        0.5,      0.5,      0.5,
    0.5,      0.5,      0.5,      0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        0.5,      0.5,      0.5,      0.5,      0.5,      0.5,
    0.333333, 0.333333, 0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        1,        1,        1,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.333333, 0.333333, 0.333333, 0.333333,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        1,        1,
    1,        1,        1,        0.5,      0.5,      0.5,      0.5,
    0.333333, 0.333333, 0.333333, 0.333333, 0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        1,        1,        1,        1,        1,
    1,        0.5,      0.5,      0.333333, 0.333333, 0.333333, 0.333333,
    0.333333, 0.333333, 0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        1,        1,        1,        1,        1,        1,
    0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        0.5,      0.5,      0.5,
    0.5,      0.5,      0.5,      0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        0.5,      0.5,      0.5,      0.5,      0.5,      0.5,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.5,      0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        1,        1,        1,        1,        1,        1,
    1,        1,        0.5,      0.5,      0.5,      0.5,      0.5,
    0.5,      0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        1,        1,
    1,        1,        1,        1,        1,        1,        0.5,
    0.5,      0.5,      0.5,      0.5,      0.5,      0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        1,        1,        1,        1,
    1,        1,        1,        1,        0.5,      0.5,      0.5,
    0.5,      0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        1,        1,        1,        1,        1,        1,
    1,        1,        0.5,      0.5,      0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        1,        1,        1,        1,        1,        1,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        1,        1,
    1,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0};

std::vector<vtkm::FloatDefault> CirBVec{
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.5,      1,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0.333333, 0.333333, 0.5,      0.5,      0.5,      0.5,      0.5,
    0.5,      1,        1,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0.333333, 0.333333, 0.333333, 0.333333,
    0.5,      0.5,      0.5,      0.5,      0.5,      1,        1,
    1,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0.333333, 0.333333, 0.333333, 0.333333, 0.5,      0.5,      0.5,
    0.5,      1,        1,        1,        1,        1,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0.333333, 0.333333, 0.333333, 0.333333,
    0.333333, 0.333333, 0.5,      0.5,      1,        1,        1,
    1,        1,        1,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 1,
    1,        1,        1,        1,        1,        1,        1,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0.5,      0.5,      0.5,
    0.5,      0.5,      0.5,      1,        1,        1,        1,
    1,        1,        1,        1,        1,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0.5,      0.5,      0.5,      0.5,      0.5,      0.5,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.5,      1,        1,        1,
    1,        1,        1,        1,        1,        1,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0.5,      0.5,      0.5,      0.5,      0.5,
    0.5,      1,        1,        1,        1,        1,        1,
    1,        1,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0.5,
    0.5,      0.5,      0.5,      0.5,      0.5,      1,        1,
    1,        1,        1,        1,        1,        1,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0.5,      0.5,      0.5,
    0.5,      1,        1,        1,        1,        1,        1,
    1,        1,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0.5,      0.5,      1,        1,        1,
    1,        1,        1,        1,        1,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    1,        1,        1,        1,        1,        1,        1,
    1,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    1,        1,        1,        0,        0,        0,        0,
    0,        0};

std::vector<vtkm::FloatDefault> CirCVec{
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        1,        1,        1,        1,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        1,        1,        1,        1,
    1,        1,        1,        1,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        1,        1,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        1,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        1,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        1,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    1,        1,        1,        1,        1,        1,        1,
    1,        1,        1,        1,        1,        1,        1,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0.5,      0.5,      0.5,
    0.5,      0.5,      0.5,      1,        1,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.5,      0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0.5,      0.5,      0.5,      0.5,      0.5,      0.5,
    0.333333, 0.333333, 0.5,      0.5,      0.5,      0.5,      0.5,
    0.5,      0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0.5,      0.5,
    0.5,      0.5,      0.5,      0.333333, 0.333333, 0.333333, 0.333333,
    0.5,      0.5,      0.5,      0.5,      0.5,      0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0.5,      0.5,      0.5,      0.5,
    0.333333, 0.333333, 0.333333, 0.333333, 0.5,      0.5,      0.5,
    0.5,      0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0.5,      0.5,      0.333333, 0.333333, 0.333333, 0.333333,
    0.333333, 0.333333, 0.5,      0.5,      0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 0.333333, 0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0,        0,        0,        0,        0,        0,
    0,        0};

class MetaDataLength : public vtkm::worklet::WorkletMapField {
public:
  using ControlSignature = void(FieldIn, FieldIn, FieldIn, FieldIn, FieldOut);

  void operator()(const vtkm::FloatDefault &background,
                  const vtkm::FloatDefault &circle_a,
                  const vtkm::FloatDefault &circle_b,
                  const vtkm::FloatDefault &circle_c, vtkm::Id &length) const {
    length = 0;
    if (background > 0)
      length++;
    if (circle_a > 0)
      length++;
    if (circle_b > 0)
      length++;
    if (circle_c > 0)
      length++;
  }
};

class MetaDataPopulate : public vtkm::worklet::WorkletMapField {
public:
  using ControlSignature = void(FieldIn, FieldIn, FieldIn, FieldIn, FieldIn,
                                WholeArrayOut, WholeArrayOut);

  template <typename IdArray, typename DataArray>
  void operator()(const vtkm::Id offset, const vtkm::FloatDefault &background,
                  const vtkm::FloatDefault &circle_a,
                  const vtkm::FloatDefault &circle_b,
                  const vtkm::FloatDefault &circle_c, IdArray &matIds,
                  DataArray &matVFs) const {
    vtkm::Id index = offset;
    if (background > 0) {
      matIds.Set(index, 1);
      matVFs.Set(index, background);
      index++;
    }
    if (circle_a > 0) {
      matIds.Set(index, 2);
      matVFs.Set(index, circle_a);
      index++;
    }
    if (circle_b > 0) {
      matIds.Set(index, 3);
      matVFs.Set(index, circle_b);
      index++;
    }
    if (circle_c > 0) {
      matIds.Set(index, 4);
      matVFs.Set(index, circle_c);
      index++;
    }
  }
};

template <typename Array> void Print5(Array array) {
  auto portal = array.ReadPortal();
  for (int i = 0; i < 5; i++) {
    std::cout << portal.Get(i) << "\t";
  }
  std::cout << std::endl;
}

vtkm::cont::DataSet MakeData(std::string dataset) {

  vtkm::io::VTKDataSetReader reader(dataset);
  vtkm::cont::DataSet data = reader.ReadDataSet();;

  for(int i = 0; i < data.GetNumberOfFields(); i++)
  {
    auto field = data.GetField(i);
    std::cout << field.GetName() << std::endl;
  }

  using IdArray = vtkm::cont::ArrayHandle<vtkm::Id>;
  using DataArray = vtkm::cont::ArrayHandle<vtkm::FloatDefault>;
  DataArray backArr;
  data.GetField("mesh_topo/background").GetData().AsArrayHandle(backArr);
  DataArray cirAArr;
  data.GetField("mesh_topo/circle_a").GetData().AsArrayHandle(cirAArr);
  DataArray cirBArr;
  data.GetField("mesh_topo/circle_b").GetData().AsArrayHandle(cirBArr);
  DataArray cirCArr;
  data.GetField("mesh_topo/circle_c").GetData().AsArrayHandle(cirCArr);
//  DataArray backArr =
//      vtkm::cont::make_ArrayHandle(BackVec, vtkm::CopyFlag::Off);
//  DataArray cirAArr =
//      vtkm::cont::make_ArrayHandle(CirAVec, vtkm::CopyFlag::Off);
//  DataArray cirBArr =
//      vtkm::cont::make_ArrayHandle(CirBVec, vtkm::CopyFlag::Off);
//  DataArray cirCArr =
//      vtkm::cont::make_ArrayHandle(CirCVec, vtkm::CopyFlag::Off);

  IdArray length;
  IdArray offset;
  IdArray matIds;
  DataArray matVFs;

  vtkm::cont::Invoker invoker;

  invoker(MetaDataLength{}, backArr, cirAArr, cirBArr, cirCArr, length);
  std::cerr << "Length : " << length.GetNumberOfValues() << std::endl;

  vtkm::Id total = vtkm::cont::Algorithm::Reduce(length, 0);
  std::cerr << "Total : " << total << std::endl;

  vtkm::cont::Algorithm::ScanExclusive(length, offset);
  std::cerr << "Offset : " << length.GetNumberOfValues() << std::endl;

  //Print5(length);
  //Print5(offset);

  matIds.Allocate(total);
  matVFs.Allocate(total);

  invoker(MetaDataPopulate{}, offset, backArr, cirAArr, cirBArr, cirCArr,
          matIds, matVFs);
  std::cerr << "IDs : " << matIds.GetNumberOfValues() << std::endl;
  std::cerr << "VFs : " << matVFs.GetNumberOfValues() << std::endl;

  //vtkm::cont::DataSetBuilderRectilinear dataSetBuilder;
  //data = dataSetBuilder.Create(XCoords, YCoords, "coords");

  data.AddField(vtkm::cont::Field("scatter_pos", vtkm::cont::Field::Association::CELL_SET, offset));
  data.AddField(vtkm::cont::Field("scatter_len", vtkm::cont::Field::Association::CELL_SET, length));
  data.AddField(vtkm::cont::Field("scatter_ids", vtkm::cont::Field::Association::WHOLE_MESH, matIds));
  data.AddField(vtkm::cont::Field("scatter_vfs", vtkm::cont::Field::Association::WHOLE_MESH, matVFs));

  return data;
};

} // namespace data
#endif
