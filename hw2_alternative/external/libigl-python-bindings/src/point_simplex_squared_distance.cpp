#include <npe.h>
#include <common.h>
#include <typedefs.h>
#include <igl/point_simplex_squared_distance.h>

const char *ds_point_simplex_squared_distance = R"igl_Qu8mg5v7(

 Determine squared distance from a point to linear simplex.
   Also return barycentric coordinate of closest point.

Parameters
----------

p  d-long query point
V  #V by d list of vertices
Ele  #Ele by ss<=d+1 list of simplex indices into V
i  index into Ele of simplex

Returns
-------
sqr_d  squared distance of Ele(i) to p
c  closest point on Ele(i)
b  barycentric coordinates of closest point on Ele(i)

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(point_simplex_squared_distance)
npe_doc(ds_point_simplex_squared_distance)

npe_arg(p, dense_float, dense_double)
npe_arg(v, npe_matches(p))
npe_arg(ele, dense_int, dense_long, dense_longlong)
npe_arg(i, int)


npe_begin_code()
  assert_valid_tet_or_tri_mesh(v, ele);
  assert_size_equals(p, v.cols(), "p");

  double  sqr_d;
  Eigen::Matrix<npe_Scalar_p, Eigen::Dynamic, 1> c;
  Eigen::Matrix<npe_Scalar_p, Eigen::Dynamic, 1> b;
  Eigen::Matrix<npe_Scalar_p, Eigen::Dynamic, 1> p_copy = p;
  if(p.size() == 2)
    igl::point_simplex_squared_distance<2>(p_copy, v, ele, i, sqr_d, c, b);
  else
    igl::point_simplex_squared_distance<3>(p_copy, v, ele, i, sqr_d, c, b);
  return std::make_tuple(sqr_d, npe::move(c), npe::move(b));

npe_end_code()


