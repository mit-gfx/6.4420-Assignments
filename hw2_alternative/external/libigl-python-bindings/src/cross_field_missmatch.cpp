#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/cross_field_mismatch.h>

const char* ds_cross_field_mismatch = R"igl_Qu8mg5v7(

Parameters
----------
V         #V by 3 eigen Matrix of mesh vertex 3D positions
F         #F by 3 eigen Matrix of face indices
PD1       #F by 3 eigen Matrix of the first per face cross field vector
PD2       #F by 3 eigen Matrix of the second per face cross field vector
isCombed  boolean, specifying whether the field is combed (i.e. matching has been precomputed.
          If not, the field is combed first.


Returns
-------
Handle_MMatch    #F by 3 eigen Matrix containing the integer mismatch of the cross field
                 across all face edges


See also
--------


Notes
-----
None

Examples
--------


)igl_Qu8mg5v7";

npe_function(cross_field_mismatch)
npe_doc(ds_cross_field_mismatch)

npe_arg(v, dense_float, dense_double)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_arg(pd1, npe_matches(v))
npe_arg(pd2, npe_matches(v))
npe_arg(is_combed, bool)


npe_begin_code()
  assert_valid_3d_tri_mesh(v, f);

  assert_rows_match(f, pd1, "F", "PD1");
  assert_rows_match(f, pd2, "F", "PD2");
  assert_cols_equals(pd1, 3, "PD1");
  assert_cols_equals(pd2, 3, "PD2");

  EigenDenseLike<npe_Matrix_v> v_copy = v;
  EigenDenseLike<npe_Matrix_f> f_copy = f;
  EigenDenseLike<npe_Matrix_v> pd1_copy = pd1;
  EigenDenseLike<npe_Matrix_v> pd2_copy = pd2;

  EigenDenseLike<npe_Matrix_f> mismatch;

  igl::cross_field_mismatch(v_copy, f_copy, pd1_copy, pd2_copy, is_combed, mismatch);
  return npe::move(mismatch);

npe_end_code()


