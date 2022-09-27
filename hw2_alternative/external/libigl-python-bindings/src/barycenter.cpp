#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/barycenter.h>

const char* ds_barycenter = R"igl_Qu8mg5v7(
Compute the barycenter of every simplex

Parameters
----------
v : #v x dim matrix of vertex coordinates
f : #f x simplex_size  matrix of indices of simplex corners into V

Returns
-------
A #f x dim matrix where each row is the barycenter of each simplex

See also
--------

Notes
-----
None

Examples
--------


)igl_Qu8mg5v7";

npe_function(barycenter)
npe_doc(ds_barycenter)

npe_arg(v, dense_float, dense_double)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_begin_code()
  assert_valid_tet_or_tri_mesh_23d(v, f);
  EigenDenseLike<npe_Matrix_v> bc;
  igl::barycenter(v, f, bc);
  return npe::move(bc);

npe_end_code()


