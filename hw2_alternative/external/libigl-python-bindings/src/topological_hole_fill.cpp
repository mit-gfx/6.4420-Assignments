#include <common.h>
#include <npe.h>
#include <typedefs.h>

#include <pybind11/stl.h>

#include <igl/topological_hole_fill.h>

const char *ds_topological_hole_fill = R"igl_Qu8mg5v7(

Topological fill hole on a mesh, with one additional vertex each hole
Index of new abstract vertices will be F.maxCoeff() + (index of hole)

Parameters
----------

F  #F by simplex-size list of element indices
b  #b boundary indices to preserve
holes vector of hole loops to fill

Returns
-------
F_filled  input F stacked with filled triangles.

See also
--------


Notes
-----
None

Examples
--------


)igl_Qu8mg5v7";

npe_function(topological_hole_fill)
npe_doc(ds_topological_hole_fill)

npe_arg(f, dense_int, dense_long, dense_longlong)
npe_arg(b, dense_int, dense_long, dense_longlong)
npe_arg(holes, std::vector<std::vector<int>>)


npe_begin_code()

  EigenDense<npe_Scalar_f> f_filled;
  igl::topological_hole_fill(f, b, holes, f_filled);
  return npe::move(f_filled);

npe_end_code()
