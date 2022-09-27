#include <common.h>
#include <npe.h>
#include <typedefs.h>




#include <igl/face_occurrences.h>

const char *ds_face_occurrences = R"igl_Qu8mg5v7(
 Count the occruances of each face (row) in a list of face indices (irrespecitive of order)
Parameters
----------
  F  #F by simplex-size

Returns
-------
  C  #F list of counts

See also
--------


Notes
-----
  Known bug: triangles/tets only (where ignoring order still gives simplex)

Examples
--------

)igl_Qu8mg5v7";

npe_function(face_occurrences)
npe_doc(ds_face_occurrences)

npe_arg(f, dense_int, dense_long, dense_longlong)


npe_begin_code()
  assert_valid_tet_or_tri_mesh_faces(f);

  EigenDenseLike<npe_Matrix_f> c;
  igl::face_occurrences(f, c);
  return npe::move(c);

npe_end_code()


