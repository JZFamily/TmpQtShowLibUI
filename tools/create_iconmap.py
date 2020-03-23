import os
from string import Template
icon_path = r".\QtCpp\ShowLib\rc"

map_str = Template('m_iconMap[${icon_name_upper}_TYPE] = QIcon(":rc/icon/${icon_name}.png");\n')
enum_str =  Template('${icon_name_upper}_TYPE,\n')
for root , dirs, files in os.walk(icon_path):
    ls_file = []
    ls_enum = []
    ls_map = []
    for file in files:
        print(file)
        file_name,ext = os.path.splitext(file)
        ls_file.append(file_name)
        ls_enum.append(enum_str.substitute(icon_name_upper = file_name.replace('-','_').upper()))
        ls_map.append(map_str.substitute(icon_name_upper = file_name.replace('-','_').upper(),icon_name = file_name))
    with open("tmp.cpp","w") as f:
        f.writelines(ls_enum)
        f.writelines(ls_map)
