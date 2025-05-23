#include "colmap/scene/point3d.h"

#include "colmap/util/logging.h"
#include "colmap/util/misc.h"
#include "colmap/util/types.h"

#include "pycolmap/helpers.h"
#include "pycolmap/pybind11_extension.h"
#include "pycolmap/scene/types.h"

#include <memory>
#include <sstream>

#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace colmap;
namespace py = pybind11;

void BindPoint3D(py::module& m) {
  py::class_ext_<Point3D, std::shared_ptr<Point3D>> PyPoint3D(m, "Point3D");
  PyPoint3D.def(py::init<>())
      .def_readwrite("xyz", &Point3D::xyz)
      .def_readwrite("color", &Point3D::color)
      .def_readwrite("error", &Point3D::error)
      .def_readwrite("track", &Point3D::track);
  MakeDataclass(PyPoint3D);

  py::bind_map<Point3DMap>(m, "Point3DMap");
}
