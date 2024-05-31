project(
  'projeto',
  'c',
)

gtk_dep = dependency('gtk+-3.0')

subdir('src/list')
subdir('src/ui')

includes = [includes_ui, include_list]

libs = lib_ui 
libs += lib_list

executable(
  'main',
  'src/main.c',
  dependencies: [gtk_dep],
  include_directories: includes,
  link_with: [libs],
)
