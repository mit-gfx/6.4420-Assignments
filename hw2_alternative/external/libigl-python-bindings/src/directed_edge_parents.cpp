#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/directed_edge_parents.h>

const char* ds_directed_edge_parents = R"igl_Qu8mg5v7(
Recover "parents" (preceding edges) in a tree given just directed edges.

Parameters
----------
e : #e by 2 list of directed edges

Returns
-------
p : #e list of parent indices into e. (-1) means root

See also
--------


Notes
-----
None

Examples
--------
e.np.random.randint(0, 10, size=(10, 2))
p = directed_edge_parents(e)
)igl_Qu8mg5v7";

npe_function(directed_edge_parents)
npe_doc(ds_directed_edge_parents)
npe_arg(e, dense_int, dense_long, dense_longlong)
npe_begin_code()

  assert_nonzero_rows(e, "e");
  assert_cols_equals(e, 2, "e");
  EigenDenseLike<npe_Matrix_e> p;
  igl::directed_edge_parents(e, p);
  return npe::move(p);

npe_end_code()


