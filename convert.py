#OpenDatabase("full_250x250.cycle_000000.root")
AddPlot("Pseudocolor", "mesh_topo/circle_a")
DrawPlots()
e = ExportDBAttributes()
e.db_type = "VTK"
e.variables = ("mesh_topo/background","mesh_topo/circle_b", "mesh_topo/circle_c")
e.filename = "full_1000x1000"
opts=GetExportOptions("VTK")
opts["FileFormat"]="Legacy Binary"
ExportDatabase(e, opts)
