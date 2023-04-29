// #include <bits/stdc++.h>
// using namespace std;

// class NonTerminal {
// 	string name;				    // Stores the Head of production rule
// 	vector<string> productionRules; // Stores the body of production rules

// public:
// 	NonTerminal(string name) {
// 		this->name = name;
// 	}

// 	// Returns the head of the production rule
// 	string getName() {
// 		return name;
// 	}

// 	void setRules(vector<string> rules) {
// 		productionRules.clear();
// 		for (auto rule : rules){
// 			productionRules.push_back(rule);
// 		}
// 	}

// 	// Returns the body of the production rules
// 	vector<string> getRules() {
// 		return productionRules;
// 	}

// 	void addRule(string rule) {
// 		productionRules.push_back(rule);
// 	}

// 	// Prints the production rules
// 	void printRule() {
// 		string toPrint = "";
// 		toPrint += name + " ->";

// 		for (string s : productionRules){
// 			toPrint += " " + s + " |";
// 		}

// 		toPrint.pop_back();
// 		cout << toPrint << endl;
// 	}
// };

// class Grammar {
// 	vector<NonTerminal> nonTerminals;

// public:
// 	// Add rules to the grammar
// 	void addRule(string rule) {
// 		bool nt = 0;
// 		string parse = "";

// 		for (char c : rule){
// 			if (c == ' ') {
// 				if (!nt) {
// 					NonTerminal newNonTerminal(parse);
// 					nonTerminals.push_back(newNonTerminal);
// 					nt = 1;
// 					parse = "";
// 				} else if (parse.size()){
// 					nonTerminals.back().addRule(parse);
// 					parse = "";
// 				}
// 			}else if (c != '|' && c != '-' && c != '>'){
// 				parse += c;
// 			}
// 		}
// 		if (parse.size()){
// 			nonTerminals.back().addRule(parse);
// 		}
// 	}

// 	void inputData() {
// 		// addRule("S -> Sa | Sb | c | d");
// 		addRule("S -> Aa");
// 		addRule("A -> Sb | c");
// 	}

// 	// Algorithm for eliminating the non-Immediate Left Recursion
// 	void solveNonImmediateLR(NonTerminal &A, NonTerminal &B) {
// 		string nameA = A.getName(); // => A
// 		string nameB = B.getName(); // => S

// 		vector<string> rulesA, rulesB, newRulesA;
// 		rulesA = A.getRules();
// 		rulesB = B.getRules();

// 		for (auto rule : rulesA) {
// 			if (rule.substr(0, nameB.size()) == nameB) {
// 				for (auto rule1 : rulesB){
// 					newRulesA.push_back(rule1 + rule.substr(nameB.size()));
// 				}
// 			}
// 			else{
// 				newRulesA.push_back(rule);
// 			}
// 		}
// 		A.setRules(newRulesA);
// 	}

// 	// Algorithm for eliminating Immediate Left Recursion
// 	void solveImmediateLR(NonTerminal &A) {
// 		string name = A.getName();
// 		string newName = name + "'";

// 		vector<string> alphas, betas, rules, newRulesA, newRulesA1;
// 		rules = A.getRules();

// 		// Checks if there is left recursion or not
// 		for (auto rule : rules) {
// 			if (rule.substr(0, name.size()) == name){
// 				alphas.push_back(rule.substr(name.size()));
// 			}
// 			else{
// 				betas.push_back(rule);
// 			}
// 		}

// 		// If no left recursion, exit
// 		if (!alphas.size())
// 			return;

// 		if (!betas.size())
// 			newRulesA.push_back(newName);

// 		for (auto beta : betas)
// 			newRulesA.push_back(beta + newName);

// 		for (auto alpha : alphas)
// 			newRulesA1.push_back(alpha + newName);

// 		// Amends the original rule
// 		A.setRules(newRulesA);
// 		newRulesA1.push_back("ε");

// 		// Adds new production rule
// 		NonTerminal newNonTerminal(newName);
// 		newNonTerminal.setRules(newRulesA1);
// 		nonTerminals.push_back(newNonTerminal);
// 	}

// 	// Eliminates left recursion
// 	void applyAlgorithm() {
// 		int size = nonTerminals.size();
// 		for (int i = 0; i < size; i++){
// 			for (int j = 0; j < i; j++){
// 				solveNonImmediateLR(nonTerminals[i], nonTerminals[j]);
// 			}
// 			solveImmediateLR(nonTerminals[i]);
// 		}
// 	}

// 	// Print all the rules of grammar
// 	void printRules() {
// 		for (auto nonTerminal : nonTerminals){
// 			nonTerminal.printRule();
// 		}
// 	}
// };

// int main(){
// 	//freopen("output.txt", "w+", stdout);

// 	Grammar grammar;
// 	grammar.inputData();
// 	grammar.applyAlgorithm();
// 	grammar.printRules();

// 	return 0;
// }


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Nonterminal{
	string name;
	vector<string> productions;
public:
	Nonterminal(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	void setProductions(vector<string> rules){
		productions.clear();
		for(string i:rules){
			productions.push_back(i);
		}
	}
	vector<string> getProductions(){
		return productions;
	}
	void addRule(string rule){
		productions.push_back(rule);
	}
	void printRules(){
		string toPrint = "";
		toPrint+=name+" ->";
		for(string i:productions){
			toPrint += " "+i+" |";
		}
		toPrint.pop_back();
		cout<<toPrint<<endl;
	}
};

class Grammar{
	vector<Nonterminal> nonterminals;

public:
	void addRule(string rule){
		string parse = "";
		bool nt = 0;
		for(char c : rule){
			if(c == ' '){
				if(!nt){
					Nonterminal nont(parse);
					nonterminals.push_back(nont);
					parse = "";
					nt = 1;
				}
				else if(parse.size()){
					nonterminals.back().addRule(parse);
					parse = "";
				}
			}
			else if(c!='-' and c!='>' and c!='|') {
				parse += c;
			}
		}
		if(parse.size()){
			nonterminals.back().addRule(parse);
		}
	}

	void solveIndirectLeftRecursion(Nonterminal &A, Nonterminal &B){
		string nameA = A.getName();
		string nameB = B.getName();

		vector<string> rulesA, rulesB, newRules;
		rulesA = A.getProductions();
		rulesB = B.getProductions();
		for(auto rule:rulesA){
			if(rule.substr(0,nameB.size())==nameB){
				for(auto rule1:rulesB){
					newRules.push_back(rule1+rule.substr(nameB.size()));
				}
			}
			else{
				newRules.push_back(rule);
			}
		}
		A.setProductions(newRules);
	}

	void solveLeftRecursion(Nonterminal &A){
		string name = A.getName();
		string newName = name+"`";
		vector<string> rules, alphas, betas, newRulesA, newRulesA1;
		rules = A.getProductions();
		for(auto rule:rules){
			if(rule.substr(0,name.size())==name){
				alphas.push_back(rule.substr(name.size()));
			}
			else{
				betas.push_back(rule);
			}
		}

		if(!alphas.size())
			return;
		if(!betas.size())
			newRulesA.push_back(newName);
		for(auto beta:betas){
			newRulesA.push_back(beta+newName);
		}
		for(auto alpha:alphas){
			newRulesA1.push_back(alpha+newName);
		}
		newRulesA1.push_back("eps");
		A.setProductions(newRulesA);
		Nonterminal nont(newName);
		nont.setProductions(newRulesA1);
		nonterminals.push_back(nont);
	}

	void applyAlgorithm(){
		int n = nonterminals.size();
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				solveIndirectLeftRecursion(nonterminals[i], nonterminals[j]);
			}
			solveLeftRecursion(nonterminals[i]);
		}
	}

	void inputGrammar(){
		addRule("S -> Aa");
		addRule("A -> Sb | c");
	}

	void printRule(){
		for(auto i:nonterminals){
			i.printRules();
		}
	}
};

int main(){
	Grammar g;
	g.inputGrammar();
	g.applyAlgorithm();
	g.printRule();
}