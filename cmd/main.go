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

	cmd "github.com/jayromofo/aleet/internal/cli"
)

func main() {

	fmt.Println("/*************************************************/")
	fmt.Println()
	fmt.Println("Hello. Welcome to Aleet CLI version 0.0001A")
	fmt.Println("Please Pick a command")
	fmt.Println()
	cmd.Execute()
}
