#!/usr/bin/env ruby
# Parses a log string to extract the sender,receiver,flags of the data

log = ARGV[0]

puts log.scan(/(?<=\[from:|\[to:|\[flags:)[^\]]+/).join(",")
