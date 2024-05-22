list(APPEND DFN_sources "${CMAKE_CURRENT_SOURCE_DIR}/FracturesAndTraces.cpp")
list(APPEND DFN_sources "${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp")
list(APPEND DFN_sources "${CMAKE_CURRENT_SOURCE_DIR}/ImportExport.cpp")


list(APPEND DFN_headers "${CMAKE_CURRENT_SOURCE_DIR}/FracturesAndTraces.hpp")
list(APPEND DFN_headers "${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp")
list(APPEND DFN_headers "${CMAKE_CURRENT_SOURCE_DIR}/ImportExport.hpp")
list(APPEND DFN_headers "${CMAKE_CURRENT_SOURCE_DIR}/PolygonalMesh.hpp")
<<<<<<< HEAD

=======
>>>>>>> 6e5c413a47ec76413f4e8ad4282f398a49fa1d7f

set(DFN_sources ${DFN_sources} PARENT_SCOPE)
set(DFN_headers ${DFN_headers} PARENT_SCOPE)
set(DFN_includes ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
