

Just unzip the desired prebuild version into this directory... or copy these files to the directory where the 'include' and 'bin' folders reside.

For each component library you want to use, go to Build Options, and for ALL configurations (root node for all configurations), go to Linker Settings, and add the name of the component library to the list...

Ngen.dll -> Ngen
Ngen.Diagnostic.dll -> Ngen.Diagnostic
etc.
etc.