#include <npe.h>
#include <common.h>
#include <typedefs.h>
#include <igl/ramer_douglas_peucker.h>

const char *ds_ramer_douglas_peucker = R"igl_Qu8mg5v7(
Run (Ramer-)Duglass-Peucker curve simplification but keep track of where
every point on the original curve maps to on the simplified curve.


Parameters
----------
P  #P by dim list of points, (use P([1:end 1],:) for loops)
tol  DP tolerance

Returns
-------
S  #S by dim list of points along simplified curve
J  #S indices into P of simplified points
Q  #P by dim list of points mapping along simplified curve

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(ramer_douglas_peucker)
npe_doc(ds_ramer_douglas_peucker)

npe_arg(p, dense_float, dense_double)
npe_arg(tol, double)


npe_begin_code()
  assert_nonzero_rows(p, "p");


  EigenDense<npe_Scalar_p> s;
  Eigen::Matrix<typename EigenDenseInt::Scalar, Eigen::Dynamic, 1> j_copy;
  EigenDense<npe_Scalar_p> q;
  igl::ramer_douglas_peucker(p, tol, s, j_copy, q);
  EigenDenseInt j = j_copy;
  return std::make_tuple(npe::move(s), npe::move(j), npe::move(q));

npe_end_code()


