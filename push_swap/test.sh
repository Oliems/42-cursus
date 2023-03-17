#!/bin/bash
for i in {1..100}
do
	bash push_swap_tester/tester.sh verif/ $i 5 | grep KO
done
