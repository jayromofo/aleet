package cli

import (
	"errors"
	"fmt"
	"os"
	"strings"

	"github.com/spf13/cobra"
	"github.com/spf13/viper"
)

var (
	cfgFile string
)

// rootCmd represents the base command when called without any subcommands
var rootCmd = &cobra.Command{
	Use:   "aleet",
	Short: "Leetcode Helper",
	Long:  `This is a tool that you can use to learn and keep track of your leetcode progress`,
	// Uncomment the following line if your bare application
	// has an action associated with it:
	PersistentPreRunE: func(cmd *cobra.Command, args []string) error {
		return initializeConfig(cmd)
	},
}

// Execute adds all child commands to the root command and sets flags appropriately.
// This is called by main.main(). It only needs to happen once to the rootCmd.
func Execute() {
	if err := rootCmd.Execute(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func init() {
	// Here you will define your flags and configuration settings.
	// Cobra supports persistent flags, which, if defined here,
	// will be global for your application.
	// rootCmd.AddCommand(statsCmd)
	// rootCmd.AddCommand(listCmd)
	// rootCmd.AddCommand(newCmd)
	// rootCmd.AddCommand(serveCmd)
	// rootCmd.AddCommand(statsCmd)

	// rootCmd.PersistentFlags().StringVar(&cfgFile, "config", "", "config file (default is $HOME/.jayromofo.yaml)")

	// Cobra also supports local flags, which will only run
	// when this action is called directly.
	rootCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
	rootCmd.PersistentFlags().StringVar(&cfgFile, "config", "", "config file (default is $HOME/aleet/config/config.yaml)")
}

func initializeConfig(cmd *cobra.Command) error {
	viper.SetEnvPrefix("ALEET")
	viper.SetEnvKeyReplacer(strings.NewReplacer(".", "*", "-", "*"))
	viper.AutomaticEnv()

	// Handle the configuration file
	if cfgFile != "" {
		viper.SetConfigFile(cfgFile)
	} else {
		// Search for a config file in the default locations
		home, err := os.UserHomeDir()
		// Only panic if we can't get home directory
		cobra.CheckErr(err)

		// Search for a config with the name "config" (without extension)
		viper.AddConfigPath(".")
		viper.AddConfigPath(home + "/.aleet/config")

		viper.SetDefault("ContentDir", "content")
		viper.SetDefault("ProblemDir", "problems")
		viper.SetDefault("ConfigDir", "config")
		viper.SetConfigName("config")
		viper.SetConfigType("yaml")

		// Read in the configuration file
		// If a config file is found, read it in. We use a robust error check
		// to ignore "file not found" errors, but panic on any other error.
		if err := viper.ReadInConfig(); err != nil {
			// It's okay if the config file dones't exist, but panic on any other error.
			var ConfigFileNotFoundError viper.ConfigFileNotFoundError
			if !errors.As(err, &ConfigFileNotFoundError) {
				return err
			}
		}
	}

	// Bind Cobra flags to viper
	// This is the magic that make flag values available through Viper.
	// It binds the full flag set of the command passed in
	err := viper.BindPFlags(cmd.Flags())
	if err != nil {
		return nil
	}
	fmt.Println("Configuration initialized. Using config file:", viper.GetViper().ConfigFileUsed())

	// Easy but useful way to config
	name := viper.Get("application.name")
	fmt.Println("Name: ", name)
	prob := viper.Get("ContentDir")
	fmt.Println("ContentDir: ", prob)

	return nil

}
