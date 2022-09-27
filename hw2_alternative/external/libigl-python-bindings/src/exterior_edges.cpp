// need assertion for a.rows = b.rows-1
// __copy
#include <npe.h>
#include <typedefs.h>
#include <common.h>





#include <igl/exterior_edges.h>

const char* ds_exterior_edges = R"igl_Qu8mg5v7(

EXTERIOR_EDGES Determines boundary "edges" and also edges with an
  odd number of occurrences where seeing edge (i,j) counts as +1 and seeing
  the opposite edge (j,i) counts as -1

Parameters
----------
F  #F by simplex_size list of "faces"

Returns
-------
E  #E by simplex_size-1  list of exterior edges

See also
--------


Notes
-----
None

Examples
--------



)igl_Qu8mg5v7";

npe_function(exterior_edges)
npe_doc(ds_exterior_edges)

npe_arg(f, dense_int, dense_long, dense_longlong)

npe_begin_code()
  assert_valid_tet_or_tri_mesh_faces(f);

  Eigen::MatrixXi e_copy;
  Eigen::MatrixXi f_copy = f.template cast<int>();
  igl::exterior_edges(f_copy, e_copy);
  EigenDenseLike<npe_Matrix_f> e = e_copy.template cast<typename npe_Matrix_f::Scalar>();
  return npe::move(e);

npe_end_code()

