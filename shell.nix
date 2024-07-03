let
  pkgs = import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/nixos-24.05.tar.gz") {};
in pkgs.mkShell {
  packages = [
    (pkgs.python3.withPackages (python-pkgs: [
      python-pkgs.setuptools
      python-pkgs.wheel
    ]))
    pkgs.unzip
    pkgs.python3.pkgs.venvShellHook
  ];
  venvDir = "./.venv";
}