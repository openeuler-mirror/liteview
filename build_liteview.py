#!/usr/bin/env python

"""编译，需要设置sdk-base-path

e.g. 
py .\build_linux_for_win.py
py .\build_linux_for_win.py -o out\linuxdebugx64
"""

import argparse
import os
import subprocess
import sys
import shutil



def main():
    parser = argparse.ArgumentParser(description=__doc__)

    parser.add_argument('-o', '--output', 
                        help='输出目录',
                        default="out/linuxdebugx64",
                        # required=True,
                        metavar='PATH')

  
    parser.add_argument('--is-component-build', 
                        help='编译动态库',
                        default="true",
                        # required=True,
                        metavar='Boolean')

    parser.add_argument('--is-debug', 
                        help='debug',
                        default="false",
                        # required=True,
                        metavar='Boolean')

    parser.add_argument('--target-cpu', 
                        help='目标cpu',
                        default="x64",
                        metavar='String')

    args = parser.parse_args()

    current_dir = os.path.dirname(os.path.realpath(__file__))
    sdk_path = os.path.join(current_dir, 'sdk_base', 'x86_64-unknown-linux-gnu', 'x86_64-unknown-linux-gnu')
    sdk_path2 = os.path.join(current_dir, 'sdk_base', 'debian_sid_arm64_sysroot')

    clang_base_path = '/usr/bin'
    ndk_include_path = '/usr/lib64/clang/17/include'

    output = os.path.realpath(args.output)
    
    gn = '/usr/bin/gn'
    ninja = '/usr/bin/ninja'
    ar = '/usr/bin/llvm-ar'
    ld = '/usr/bin/ld.lld'

    is_debug = args.is_debug # 'true'
    target_cpu = args.target_cpu
    is_component_build = args.is_component_build
    custom_toolchain = '//gn/toolchain/posix:livi_x64'

    gn_cmd = '\"{}\" gen \"{}\" --args=\"is_debug={} is_component_build={} target_cpu=\\\"{}\\\" target_os=\\\"linux\\\" is_clang=true is_livi_custom=true custom_toolchain=\\\"{}\\\" sdkPath=\\\"{}\\\" sdkPath2=\\\"{}\\\" ndkIncludePath=\\\"{}\\\" clang_base_path=\\\"{}\\\" ar=\\\"{}\\\" ld=\\\"{}\\\"" '.format(
        gn,
        output,
        is_debug,
        is_component_build,
        target_cpu,
        custom_toolchain,
        sdk_path,
        sdk_path2,
        ndk_include_path,
        clang_base_path,
        ar,
        ld)
    print('gn command: ' + gn_cmd)
    result = subprocess.call(gn_cmd, shell = True)
    
    if result == 0:
        ninja_cmd = '\"{}\" -C \"{}\"'.format(ninja, output)
        print('ninja command: ' + ninja_cmd)
        result = subprocess.call(ninja_cmd, shell = True)
    
    if result == 0:
        dst_dir_name = 'livi-browser'
        dstdir = os.path.join(current_dir, dst_dir_name)
        shutil.rmtree(dstdir, ignore_errors=True)
        os.makedirs(dstdir)

        srcdir =  os.path.join(current_dir, args.output)

        srcfile1 = os.path.join(srcdir, "liteview")
        dstfile1 = os.path.join(dstdir, "liteview")
        shutil.copy2(srcfile1, dstfile1)

        srcfile2 = os.path.join(srcdir, "livicore")
        dstfile2 = os.path.join(dstdir, "livicore.so")
        shutil.copy2(srcfile2, dstfile2)

        srcfile3 = os.path.join(sdk_path2, "usr", "lib", "x86_64-linux-gnu/libffmpeg.so")
        dstfile3 = os.path.join(dstdir, "libffmpeg.so")
        shutil.copy2(srcfile3, dstfile3)

        return result


if __name__ == "__main__":
    sys.exit(main())
