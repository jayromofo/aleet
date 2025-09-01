package main

// "github.com/spf13/cobra"     // Command structure, flags, subcommands
// "github.com/spf13/viper"     // Configuration management
// "net/http"
// "encoding/json"
// "os"
// "fmt"
// "github.com/schollz/progressbar/v3"

import (
	"fmt"
	"os"

	cmd "github.com/jaycode/internal/cli"
)

func main() {

	fmt.Println("Hello World")

	generateCppFile("two-sum")
	/*
		viper.SetDefault("ContentDir", "content")
		viper.SetDefault("ProblemDir", "problems")
		viper.SetDefault("ConfigDir", "config")

		viper.SetConfigName("config")
		viper.SetConfigType("yaml")
		viper.AddConfigPath("config/")
		viper.AddConfigPath(".")

		if err := viper.ReadInConfig(); err != nil {
			if _, ok := err.(viper.ConfigFileNotFoundError); ok {
				panic(fmt.Errorf("fatal error config file not found: %w", err))
			} else {
				panic(fmt.Errorf("fatal error config file: %w", err))
			}
		}

		fmt.Println("Config Read")
		// Bind Cobra flags to viper
		// This is the magic that make flag values available through Viper.
		// It binds the full flag set of the command passed in
		err := viper.BindPFlags(cmd.Flags())
		if err != nil {
			return nil
		}

		// Easy but useful way to config
		name := viper.Get("application.name")
		fmt.Println("Name: ", name)
		prob := viper.Get("ContentDir")
		fmt.Println("ContentDir: ", prob)
	*/
	cmd.Execute()

}

// Create a template in
func generateCppFile(problem string) error {
	if err := os.MkdirAll("src", 0755); err != nil {
		return fmt.Errorf("failed to create src directory: %w", err)
	}

	return nil

	// Clean the content for C++ comments
	// cleanContent := strings.Replace("cpp")
}
