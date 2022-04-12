# DNA_Project

Section 1 - Cerebration Sessions - Brainstorming and Initial Design

Identified Unmet Needs
The first need that we identified that we wanted to solve is the difficulty for new people to get into investing and managing their money well. Oftentimes, people who are not familiar with the stock market and how to trade intelligently are completely turned away from the idea, despite low-risk investments being a great way to improve one’s wealth. Our idea was to implement a program that used trends to predict how stocks would do in the market. However, we realized the difficulty of accurately predicting trends and felt that this task would not be a great fit for this project. So we decided not to move forward with this idea.

Next, we thought about the uncertainty that high school students applying to college go through, and how we could come up with a program that would aid that process. We thought about trying to obtain college admission data and using it to determine the likelihood of a student getting into a particular university, based on their GPA, classes taken, extracurricular activities, race, and hometown. We came to the conclusion, though, that getting access to this type of data would be extremely difficult and decided to continue brainstorming.

Then, we thought about how algorithms could be used with DNA sequences to gain important information, such as scanning for disabilities, testing for who a child belongs to, and searching for genetic mutations. We searched for data on these issues with mixed results, but we did find an article about the correlation between DNA sequencing and Huntington’s disease. Huntington’s is one of the most common diseases that can be found from DNA strands. Another reason we chose to work on this project is that we can apply our knowledge of data structures to store the genome sequences efficiently by using a bitset.
Thought Questions
Where can we find data to use?
In what way can we use data structures for this project?
Who would be the user?
Who can benefit from this project?
 
Resource Availability and Restrictions
Available Resources:
Plentiful existing research on DNA and how it links to diseases
Boyer Moore algorithm for pattern searching
Internet to do further research
Existing C++ libraries
Project Manager Timothy Fitzpatrick
Project Director Matt Morrison
Restrictions:
Minimal experience working with DNA and sequencing
Computing power and time
Need to access long DNA sequences quickly and efficiently
 
Identifying Risks and Alternatives
Risk: Sequencing whole DNA strand takes too long
Alternative: Use smaller portions of DNA, losing precision, but improving runtime
Risk: The DNA generator does not work well with what we want to do
Alternative: Find another source of DNA
Risk: We cannot accurately predict Huntington’s disease
Alternative: Shift our focus to gene mutations or genetic relations
 
Discussion and Debate
Discussion Topic: Issue to Focus on
Refer to section 1
Discussion Topic: Language to use
We debated at length about whether to use Python or C++ to complete our project. Python provides a level of abstraction that C++ cannot touch, which made it an extremely intriguing option. We felt that the Python libraries would come in handy and would allow us to perform tasks more easily. However, not everyone in our group is as comfortable with Python as we are with C++, which could have led to bigger problems down the road. Additionally, we have been implementing data structures in C++ all year and have countless resources available on the language throughout the semester. Therefore, we chose to use C++.
Discussion Topic: What to use the DNA to search for
We were all extremely excited about using DNA sequencing to aid areas of need in the world. However, we were passionate about multiple different issues and needed to discern which fit the best for the scope of the project and which would be the most feasible to research and implement an algorithm for
 
Opportunities for Proof of Concept
“Back of Napkin” sketch / flow of program:

While we need to think more specifically about the specifications of which data structures and sequencing algorithms to use, as well as how to most efficiently scan the data, this is our rough idea of what our algorithm might look like.

Section 2 - Key Terms and Definitions

Nucleotides: Form the basic structural unit of nucleic acids like DNA and RNA. Includes: adenine (A), thymine (T), guanine (G), and cytosine (C)
Down Syndrome: Also known as Trisomy 21, it is a genetic disorder caused by the presence of all or part of an extra copy of chromosome 21. Associated with physical growth delays and mild intellectual disability.
Patau Syndrome: Also known as Trisomy 13, it is a syndrome caused by the presence of extra genetic material from chromosome 13 in some or all of the cells in the body. The extra genetic material causes multiple, complex organ defects.
Edwards Syndrome: Also known as Trisomy 18, it is a syndrome caused by an extra copy of chromosome 18 and is considered a life-limiting condition as around 5 in 10 live longer than a week and 1 in 10 may live longer than 5 years.
Cystic Fibrosis: A genetic disorder caused by a mutation in the cystic fibrosis transmembrane conductance regulator (CFTR) gene that alters the regulation of movement of salt in and out of cells. Results in thickening of the mucus.
Sickle Cell Disease: A group of inherited red blood cell disorders that is inherited from the recessive sickle cell gene. Causes a change in the shape of red blood cells.
DNA Sequence: the exact sequence of bases (A, C, G, T) in a DNA molecule. DNA sequence information is important to scientists investigating the functions of the genome.
Sequence Analysis: The process of subjecting a DNA, RNA or peptide sequence to any of a wide range of analytical methods to understand its features, function, structure, or evolution. Methodologies used include sequence alignment, searches against biological databases, and others.
Sequence Motif: Short, recurring pattern in DNA that is presumed to have a biological function. Often indicates sequence-specific binding sites for proteins such as nucleases and transcription factors.


Section 3 - Project Introduction Statement

The objective of this project is to build a program that can determine if an individual has certain diseases based on their DNA sequence. Certain DNA patterns are linked with diseases, such as Huntington’s. Given a DNA strand, our program will scan its sequence and determine if there exist any potentially problematic sequences. Our goal is to create a tool that could allow its user to search for certain patterns within a DNA strand that correlate to relations or disabilities, as well as to promote learning and development in this area of science.


Section 4 - Design Considerations
Assumptions
Assume DNA sequence data is valid and only has A, C, G, and T as elements of the input strings.
Student machines are powerful enough to handle the storage, processing, and analysis of the DNA sequences (within a reasonable amount of time).
Some of the input DNA sequences will represent persons with Huntington’s Disease (not a random sampling).
Project Requirements
The project will read in a sequence of DNA from a text file.
The user will be prompted for input to search for a specific motif/make a comparison, etc. To be further specified later.
The project will use a searching algorithm to search for said motif, and output to the user if the motif was found, along with frequency/length of motif. Such as: Disease was found.
Specifications
Require text file with valid dna strand to be read in.
The program will read in the data and process it as either a bitset or an array, converting the bases (A, C, G, T) into a more size efficient form, such as 00, 01, 10, and 11.
Initial Risks and Alternatives
Long DNA sequence will lead to inefficient run time
Alternative: There is no alternative to this issue, it is just something we will have to deal with
Finding a valid source to get the DNA strands from
Alternative: If it turns out that our current DNA generator does not work with what we are trying to do, we will do further research to find other sources to get the DNA strands from
Risk: We cannot accurately predict Huntington’s disease
Alternative: Shift our focus to gene mutations or genetic relations
Artifacts
April 8 8AM - 5PM: Felix SIBC Presentation
April 12 8AM: Duncan exam
April 12 8 - 10PM: Max Young Life event
April 14 8AM: Duncan and George have Linear Algebra exam
April 14 - 18: People away for easter
April 20: Felix Real Estate Case Study
TBD: Logic Design Final Project

Section 5 - Implementation of Data Structures Course Concepts

We will be coding our project in C++. We plan to implement either a bitset or an array. If we use a bitset it will store the values for A, C, G, and T as 00, 01, 10, and 11, respectively. Instead, if we choose to use an array, we will store the values as characters (i.e. ‘A’, ‘C’, etc.). While an array of chars can store up to 256 different values (using 8 bits each), we only have 4 different chars to work with. On the other hand, a bitset only requires 2 bits to store our values. Because of this, implementing a bitset could drastically increase the efficiency of our program. If we choose to go this route, we must include the <bitset> library in order to access the std::bitset methods. A simple case statement and scan can be implemented to store the values from a text file into the bitset. 

We will ask the user to either input a certain motif to search for, or search for a certain disease such as Huntington’s Disease. Then, we will use an algorithm to search for these patterns - as of right now, we plan on implementing the Boyer-Moore algorithm, which is a widely used pattern recognition algorithm for DNA strands. This algorithm can take on 1 of 2 different approaches. The bad character heuristic works by shifting the data set until a mismatch becomes a match, or by shifting the pattern past a mismatched character. The good suffix heuristic works by shifting the pattern to the right by the least amount that guarantees not to skip any occurrence of the good-suffix already matched. With the use of either an array or a bitset, this algorithm should perform relatively quickly and efficiently considering the length of the DNA sequences we will be testing.

Section 6 - Goals and Timeline
Project Proposal Draft – Due April 7
April 8: Email project manager to set up meeting to discuss draft
TBD: Meet with Project Manager
Same day as meeting: Teem meeting to discuss changes and assign responsibilities
April 11: Individual responsibilities due by 5pm
April 11 5pm: Team meeting to finalize changes, review proposal, and assign coding responsibilities for checkpoint 1
Final Draft Due April 11
April 14: Team code and memo check-in & Finalize Checkpoint 1 material
Checkpoint 1 Code Review and Memorandum – Due April 15 
April 20: Team code and memo check-in
April 22: Finalize Checkpoint 2 material
Checkpoint 2 Code Review and Memorandum – Due April 22
April 22: Team code and memo check-in
April 26: Finalize project
Final Submission – Due April 26
