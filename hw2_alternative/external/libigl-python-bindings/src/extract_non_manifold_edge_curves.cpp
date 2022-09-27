#include <npe.h>
#include <common.h>
#include <typedefs.h>
#include <pybind11/stl.h>



#include <igl/extract_non_manifold_edge_curves.h>

const char *ds_extract_non_manifold_edge_curves = R"igl_Qu8mg5v7(

Extract non-manifold curves from a given mesh.
     A non-manifold curves are a set of connected non-manifold edges that
     does not touch other non-manifold edges except at the end points.
     They are also maximal in the sense that they cannot be expanded by
     including more edges.

Assumes the input mesh have all self-intersection resolved.  See ``igl::cgal::remesh_self_intersection`` for more details.

Parameters
----------
F  #F by 3 list representing triangles.
uE2E  #uE list of lists of indices into E of coexisting edges.

Returns
-------

curves  An array of arries of unique edge indices.

See also
--------


Notes
-----
None

Examples
--------

)igl_Qu8mg5v7";

npe_function(extract_non_manifold_edge_curves)
npe_doc(ds_extract_non_manifold_edge_curves)

npe_arg(f, dense_int, dense_long, dense_longlong)
npe_arg(u_e2_e, std::vector<std::vector<int> >)


npe_begin_code()
  assert_valid_tri_mesh_faces(f);

  EigenDenseLike<npe_Matrix_f> emap;


  std::vector<std::vector<size_t> > curves;
  igl::extract_non_manifold_edge_curves(f, emap, u_e2_e, curves);
  return curves;

npe_end_code()


