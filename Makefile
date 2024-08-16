s = ~/.config/Code/User/snippets/cp-cpp.code-snippets # snippet file address
t = . # template folder address
l = cpp # language

all:
	python3 vscode.py -s $s -t $t -l $l

help:
	python3 vscode.py -h