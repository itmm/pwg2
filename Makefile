pwg2: pwg2.cpp

pwg2.cpp: README.md
	@echo "mdp $<"
	@which mdp >/dev/null && mdp $< || echo "please install markdown-patcher" 1>&2
