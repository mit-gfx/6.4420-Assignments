#include <common.h>
#include <npe.h>
#include <igl/avg_edge_length.h>

const char* ds_avg_edge_length = R"igl_Qu8mg5v7(
Compute the average edge length for the given triangle mesh.

Parameters
----------
v : array_like #v by 3 vertex array
f : f #f by simplex-size list of mesh faces (must be simplex)

Returns
-------
l : average edge length

See also
--------
adjacency_matrix

Notes
-----
None

Examples
--------
# Mesh in (v, f)
>>> length = avg_edge_length(v, f)
)igl_Qu8mg5v7";

npe_function(avg_edge_length)
npe_doc(ds_avg_edge_length)
npe_arg(v, dense_double, dense_float)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_begin_code()

  assert_valid_tet_or_tri_mesh(v, f);
  return igl::avg_edge_length(v, f);

npe_end_code()


