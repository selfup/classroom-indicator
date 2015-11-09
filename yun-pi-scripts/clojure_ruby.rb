require 'nokogiri'
require 'open-uri'

COHORTS = %w(1505 1507 1508 1510)

content = Nokogiri::HTML(open('http://today.turing.io/outlines/2015-11-09'))

doc = content.text.gsub!("\n", "").split(" ")

doc = doc.reject { |element| element == ''}

# classrooms = {}

#
# CHORTS.each do |cohort|
#   classrooms[:cohort] = nil
# end
#
# classrooms = elements.each do |element|
#   if element.include?('Classroom')
#
# end



# lines = ["1505", "a thing", "another thing", "asdfasdf", "1507", "asdfasdf", "asdfasdf", "13131"]

items = []

while l = doc.first
  if l.start_with?("15")
    items << [l]
  else
    items.last << l
  end
  doc = lines[1..-1]
end

chunked = items.map do |cohort|
  [cohort.first, cohort[1..-1]]
end


Hash[chunked]
