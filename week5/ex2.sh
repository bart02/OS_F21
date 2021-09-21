while [ true ]
  do
    if ln a.txt a.txt.lock 2>&-; then
      a=$(tail -n1 a.txt)
      a=$((a+1))
      echo $a >> a.txt
      rm -f a.txt.lock
    else
      echo locked
      continue
    fi
  done
