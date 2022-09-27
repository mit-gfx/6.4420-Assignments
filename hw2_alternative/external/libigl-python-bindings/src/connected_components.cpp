#include <common.h>
#include <npe.h>
#include <typedefs.h>

#include <igl/connected_components.h>

const char *ds_connected_components = R"igl_Qu8mg5v7(

Determine the connected components of a graph described by the input
   adjacency matrix (similar to MATLAB's graphconncomp).

Parameters
----------

A  #A by #A adjacency matrix (treated as describing an undirected graph)

Returns
-------
Returns number of connected components
C  #A list of component indices into [0,#K-1]
K  #K list of sizes of each component

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(connected_components)
npe_doc(ds_connected_components)

npe_arg(a, sparse_int, sparse_long, sparse_longlong)


npe_begin_code()
   assert_nonzero_rows(a, "A");
   assert_cols_equals(a, a.rows(), "A");
   Eigen::SparseMatrix<npe_Scalar_a> a_copy = a;
   EigenDense<npe_Scalar_a> c;
   EigenDense<npe_Scalar_a> k;
   const int comps = igl::connected_components(a_copy, c, k);
   return std::make_tuple(comps, npe::move(c), npe::move(k));

npe_end_code()


