/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package cli

import (
	"fmt"
	"strconv"
	"time"

	"github.com/jayromofo/aleet/internal/generator"
	"github.com/spf13/cobra"
)

// newCmd represents the new command
var newCmd = &cobra.Command{
	Use:   "new",
	Short: "Create a new problem to solve",
	Run: func(cmd *cobra.Command, args []string) {
		problemNumber := args[0]
		// problemTitle := args[1]

		d := time.Now()

		data := generator.ProblemData{
			Author:        "Jason Rossetti",
			Date:          d.Format("010206"),
			ProblemNumber: problemNumber,
			ProblemTitle:  "This is a problem",
			Difficulty:    "Medium",
			Description:   "Reverse Vowels of a String",
			LongDate:      d.Month().String() + " " + strconv.Itoa(d.Day()) + " " + strconv.Itoa(d.Year()),
		}

		filepath := fmt.Sprintf("./problems/src/%s-%s.cpp", data.Date, data.ProblemNumber)

		ok := generator.GenerateCppFile(&data, filepath)
		if ok != nil {
			println("Unable to create file: ", ok)
		}
	},
}

func init() {
	rootCmd.AddCommand(newCmd)

	// Here you will define your flags and configuration settings.

	// Cobra supports Persistent Flags which will work for this command
	// and all subcommands, e.g.:
	// newCmd.PersistentFlags().String("foo", "", "A help for foo")

	// Cobra supports local flags which will only run when this command
	// is called directly, e.g.:
	// newCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
}
