project('demo', 'c', version : '1.0', license : 'GPL')

foo = shared_library('foo', ['foo.c'], version : '1.0', install : true)

executable('x', 'x.c', link_with: foo, install : true,
   # Without this, meson strips rpath entirely upon install :-(
   install_rpath : join_paths([get_option('prefix'), get_option('libdir')])
)
