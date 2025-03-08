find . \( -name '*.c' -or -name '*.h' -or -name '*.asm' -or -name '*.as' -or -name '*.ld' -or -name '*.s' -or -name '*.sh' \) -print0 | xargs -0 wc -l
