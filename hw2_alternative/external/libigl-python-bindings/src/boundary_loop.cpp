#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/boundary_loop.h>
#include <pybind11/stl.h>

const char* ds_boundary_loop = R"igl_Qu8mg5v7(
Compute ordered boundary loops for a manifold mesh and return the longest loop in terms of vertices.

Parameters
----------
f : #v by dim array of mesh faces

Returns
-------
l : ordered list of boundary vertices of longest boundary loop

See also
--------


Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>>l = boundary_loop(f)
)igl_Qu8mg5v7";

npe_function(boundary_loop)
npe_doc(ds_boundary_loop)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_begin_code()

  assert_valid_tri_mesh_faces(f);
  EigenDenseLike<npe_Matrix_f> l;
  igl::boundary_loop(f, l);
  return npe::move(l);

npe_end_code()



const char* ds_all_boundary_loop = R"igl_Qu8mg5v7xx(
Compute ordered boundary loops for a manifold mesh

Parameters
----------
f : #v by dim array of mesh faces

Returns
-------
l : list of loops where l[i] = ordered list of boundary vertices in loop i

See also
--------


Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>>l = all_boundary_loop(f)
)igl_Qu8mg5v7xx";

npe_function(all_boundary_loop)
npe_doc(ds_all_boundary_loop)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_begin_code()
  assert_valid_tri_mesh_faces(f);
  std::vector<std::vector<typename EigenDenseI64::Scalar>> l;
  igl::boundary_loop(f, l);
  return l;

npe_end_code()

