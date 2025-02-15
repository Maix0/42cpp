{
  description = "Flake utils demo";

  inputs.nixpkgs.url = "github:nixos/nixpkgs";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        devShell = pkgs.mkShellNoCC {
          packages = with pkgs;
            [
              (clang-analyzer.override {
                clang = pkgs.llvmPackages_18.clang;
                llvmPackages = pkgs.llvmPackages_18;
              })
              clang
              gnumake
              llvmPackages_18.bintools
              tokei
              coreutils
              tree
              poppler_utils
            ]
            ++ (
              if system == "x86_64-linux" || system == "aarch64-linux"
              then [valgrind valgrind.dev]
              else []
            );
        };
      }
    );
}
