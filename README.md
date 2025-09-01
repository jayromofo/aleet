leetcode-cli/
├── cmd/
│   ├── root.go          # Root command setup
│   ├── new.go           # New problem command
│   ├── list.go          # List problems command
│   └── stats.go         # Statistics command
├── internal/
│   ├── leetcode/
│   │   ├── client.go    # LeetCode API client
│   │   └── types.go     # Problem structs
│   ├── generator/
│   │   ├── cpp.go       # C++ file generation
│   │   └── templates.go # Code templates
│   └── storage/
│       ├── progress.go  # Progress tracking
│       └── config.go    # Configuration
├── templates/
│   ├── cpp.tmpl         # C++ template file
│   └── test.tmpl        # Test template
├── problems/
│   ├── src/             # Work in progress
│   │   ├── 01-two-sum.cpp
│   │   └── 02-add-two.cpp
│   ├── solved/          # Completed solutions
│   └── build/           # Compiled binaries
├── config/
│   └── config.yaml      # CLI configuration
├── Makefile             # C++ compilation
├── go.mod
├── go.sum
├── main.go              # Entry point
└── README.md

# Common GraphQL Queries
- questionOfToday
- userProfile
- userContestRanking
- questionList
- problemsetQuestionList
- submissionList