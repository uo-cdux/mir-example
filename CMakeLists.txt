##============================================================================
##  Copyright (c) Kitware, Inc.
##  All rights reserved.
##  See LICENSE.txt for details.
##
##  This software is distributed WITHOUT ANY WARRANTY; without even
##  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
##  PURPOSE.  See the above copyright notice for more information.
##============================================================================
cmake_minimum_required(VERSION 3.8...3.15 FATAL_ERROR)

project(mirtest CXX)

# Find the VTK-m package
find_package(VTKm REQUIRED QUIET)

add_executable(mirtest mirtest.cxx makedata.h)
target_link_libraries(mirtest PRIVATE vtkm_cont vtkm_filter vtkm_io)
vtkm_add_target_information(mirtest
                            DROP_UNUSED_SYMBOLS MODIFY_CUDA_FLAGS
                            DEVICE_SOURCES mirtest.cxx)
if(TARGET vtkm::tbb)
  target_compile_definitions(mirtest PRIVATE BUILDING_TBB_VERSION)
endif()

