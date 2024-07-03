from setuptools import setup, Extension, find_packages

setup(
    name='root',
    version='1.1',
    description='Package A & B with C extension',
    ext_modules=[Extension('a.ext',
                   sources=['src/a/ext.c'],
                   libraries=["foo"],
                   library_dirs=["./src/a/libfoo"]),
                Extension('b.ext',
                   sources=['src/b/ext.c'],
                   libraries=["foo"],
                   library_dirs=["./src/b/libfoo"])],
    packages=find_packages(
        where='src',
        include=['a*', 'b*'],
    ),
    package_dir={"": "src"}
)
