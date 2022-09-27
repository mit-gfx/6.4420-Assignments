#include <common.h>
#include <npe.h>
#include <typedefs.h>
#include <igl/extract_manifold_patches.h>

const char *ds_extract_manifold_patches = R"igl_Qu8mg5v7(
Extract a set of maximal patches from a given mesh.
     A maximal patch is a subset of the input faces that are connected via
     manifold edges; a patch is as large as possible.

Parameters
----------
      F  #F by 3 list representing triangles.

Returns
-------
number of manifold patches.
P  #F list of patch indices.

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(extract_manifold_patches)
npe_doc(ds_extract_manifold_patches)

npe_arg(f, dense_int, dense_long, dense_longlong)


npe_begin_code()
  assert_valid_tri_mesh_faces(f);
  EigenDenseLike<npe_Matrix_f> p;
  int n_patches = igl::extract_manifold_patches(f, p);
  return std::make_tuple(n_patches, npe::move(p));

npe_end_code()
