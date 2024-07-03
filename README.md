# There is no free lunch

This is a small demo to show that semantic versioning doesn't help at all when thinking about shared object libraries that are dependencies on C extensions in Python.

Manylinux / auditwheel attempts to solve this issue by embedding the dependencies in the wheel itself, but alas, there can only be 1 shared object loaded by SONAME so we are back at the original problem.