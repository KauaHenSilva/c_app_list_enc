project('projeto', 'c')

gtk_dep = dependency('gtk+-3.0')

subdir('src/listEnc')
subdir('src/ui')

executable(
  'main',
  'src/main.c',
  dependencies: [gtk_dep],
  link_with: [ui_lib]
)

configure_file(input: 'screen.ui', output: 'screen.ui', copy: true)