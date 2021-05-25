# SPDX-License-Identifier: Apache-2.0
#!/bin/sh
cmake -S . -B build -G Ninja
pushd build && ninja -v && popd
