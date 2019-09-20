int main(void) {
	// ... DO SOMETHING ... //
	if(flag) goto yes;
	else if(flag2) goto no;
	else goto yes;
	// ..... //
yes:
	cout << "YES_STRING" << ENDL;
no:
	cout << "NO_STRING" << ENDL;
}