#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/is_intrinsic_delaunay.h>

const char *ds_is_intrinsic_delaunay = R"igl_Qu8mg5v7(

IS_INTRINSIC_DELAUNAY Determine if each edge in the mesh (V,F) is Delaunay.


Parameters
----------
     l  #l by dim list of edge lengths
     F  #F by 3 list of triangles indices

Returns
-------

D  #F by 3 list of bools revealing whether edges corresponding 23 31 12
       are locally Delaunay. Boundary edges are by definition Delaunay.
       Non-Manifold edges are by definition not Delaunay.

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(is_intrinsic_delaunay)
npe_doc(ds_is_intrinsic_delaunay)

npe_arg(l, dense_float, dense_double)
npe_arg(f, dense_int, dense_long, dense_longlong)


npe_begin_code()
  assert_rows_match(l, f, "l", "f");
  assert_cols_equals(l, 3, "l");
  assert_valid_tri_mesh_faces(f);

  EigenDense<bool> d;
  igl::is_intrinsic_delaunay(l, f, d);
  return npe::move(d);

npe_end_code()

