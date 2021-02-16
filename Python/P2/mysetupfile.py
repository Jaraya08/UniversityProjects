from distutils.core import setup 
import py2exe 
 
setup(name="Agenda Virtual Universal", 
version="1.0", 
description="Calendario", 
author="Jordan Araya Leiva", 
author_email="jordan.kn08@gmail.com", 
url="url del proyecto", 
license="ninguna", 
scripts=["Agenda Virtual Universal.py"], 
console=["Agenda Virtual Universal.py"], 
options={"py2exe": {"bundle_files":1}}, 
zipfile=None)
