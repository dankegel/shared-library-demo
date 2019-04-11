project('demo', 'c', version : '1.0', license : 'GPL')

foo = shared_library('foo', ['foo.c'], version : '1.0', install : true)

bar = shared_library('bar', ['bar.c'], version : '1.0', install : true,
   link_with: foo,
   install_rpath : join_paths([get_option('prefix'), get_option('libdir')]),
)

executable('x', 'x.c', install : true,
   link_with: bar,
   install_rpath : join_paths([get_option('prefix'), get_option('libdir')]),
)
