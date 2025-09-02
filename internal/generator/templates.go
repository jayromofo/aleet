package generator

import (
	"os"
	"text/template"
)

type ProblemData struct {
	Author        string
	Date          string
	LongDate      string
	ProblemNumber string
	ProblemTitle  string
	Difficulty    string
	Description   string
	CodeTemplate  string
	TestCases     []string
}

func GenerateCppFile(data *ProblemData, outputPath string) error {
	tmpl, err := template.ParseFiles("templates/cpp.tmpl")
	if err != nil {
		return err
	}

	file, err := os.Create(outputPath)
	if err != nil {
		return err
	}
	defer file.Close()

	return tmpl.Execute(file, data)
}
