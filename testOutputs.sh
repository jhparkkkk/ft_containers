#!/bin/bash
printy() {
  printf "\e[33;1m%s" "$1"
}
printg() {
  printf "\e[32m$1\e[m\n"
}
printr() {
  echo -e "\033[1;31m$1\033[0m"
}

printy "Checking diff between ft_output and std_output"

# for ((i=0;i<3;i++))
#     do
#         sleep 0.2
#         printy "."
#     done

./ft_containers > ft_output
./std_containers > std_output
diff ft_output std_output > diff
if ! diff -q ft_output std_output &>/dev/null; then
  >&2 printr "\n ❌ Fail: ft_output and std_output are different"
        cat diff
  else
    printg "\n✅ Success: My ft containers behave just like std!"
fi

