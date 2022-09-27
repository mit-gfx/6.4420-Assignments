#include <common.h>
#include <npe.h>
#include <typedefs.h>






#include <igl/massmatrix_intrinsic.h>

const char *ds_massmatrix_intrinsic = R"igl_Qu8mg5v7(

Constructs the mass (area) matrix for a given mesh (V,F).


Parameters
----------
l  #l by simplex_size list of mesh edge lengths
F  #F by simplex_size list of mesh elements (triangles or tetrahedra)
type  one of the following ints:
       -igl.MASSMATRIX_TYPE_BARYCENTRIC  barycentric
       -igl.MASSMATRIX_TYPE_VORONOI voronoi-hybrid (default)
       -igl.MASSMATRIX_TYPE_FULL full (not implemented)

Returns
-------
M  #V by #V mass matrix

See also
--------
adjacency_matrix

Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(massmatrix_intrinsic)
npe_doc(ds_massmatrix_intrinsic)

npe_arg(l, dense_float, dense_double)
npe_arg(f, dense_int, dense_long, dense_longlong)
npe_default_arg(type, int, 1)


npe_begin_code()
  assert_rows_match(l, f, "l", "f");
  assert_cols_equals(l, 3, "l");
  assert_valid_tri_mesh_faces(f);

  static_assert(int(igl::MASSMATRIX_TYPE_BARYCENTRIC) == 0, "ARAPEnergyType enum changed!");
  static_assert(int(igl::MASSMATRIX_TYPE_VORONOI) == 1, "ARAPEnergyType enum changed!");
  static_assert(int(igl::MASSMATRIX_TYPE_FULL) == 2, "ARAPEnergyType enum changed!");
  static_assert(int(igl::MASSMATRIX_TYPE_DEFAULT) == 3, "ARAPEnergyType enum changed!");
  static_assert(int(igl::NUM_MASSMATRIX_TYPE) == 4, "ARAPEnergyType enum changed!");

  if (type >= igl::NUM_MASSMATRIX_TYPE)
  {
    std::string errmsg =
        std::string("Invalid enum for type should be in the range 0 to ") +
        std::to_string(igl::NUM_MASSMATRIX_TYPE - 1);
    throw pybind11::value_error(errmsg);
  }

  Eigen::SparseMatrix<npe_Scalar_l> m;
  igl::massmatrix_intrinsic(l, f, igl::MassMatrixType(type), m);
  return npe::move(m);

npe_end_code()
