########################################################
# 				Universidad Simon Bolivar				#
# 				Inteligencia Artificial II 				#
# 					Proyecto 2: Gabil 					#
#  														#
# 						Grupo 05						#
#														#
# 				Juliana Leon		08-10608 			#
# 				Stefano De Colli	09-10203			#
# 				Karen Troiano		09-10855			#
########################################################

from random import randint as rand_randint, uniform as rand_uniform, choice as rand_choice, randrange as randrange
from pyevolve import G1DBinaryString
from pyevolve import GSimpleGA
from pyevolve import *
import sys

TRAINING_SET = []
SAMPLE_SET = []
MAX_SET_SIZE = 3
RULE_SIZE = 32
MAX_RULE_SIZE = 128
GENERATIONS = 1000
INIT_POP = 10

#######################
#######################
#####  Atributos  #####
#######################
#######################

# Sepal_length
#    5 bits
def atributo01(num):
	if (num >= 4.0 and num < 5.0):
		return '10000'
	if (num >= 5.0 and num < 5.5):
		return '01000'
	if (num >= 5.5 and num < 6.0):
		return '00100'
	if (num >= 6.0 and num < 6.5):
		return '00010'
	return '00001'

# Sepal_whidth
#    6 bits
def atributo02(num):
	if (num >= 2.0 and num < 2.5):
		return '100000'
	if (num >= 2.5 and num < 2.8):
		return '010000'
	if (num >= 2.8 and num < 3.0):
		return '001000'
	if (num >= 3.0 and num < 3.25):
		return '000100'
	if (num >= 3.25 and num < 3.75):
		return '000010'
	return '000001'

# Petal_length
#    8 bits
def atributo03(num):
	if (num >= 1.0 and num < 1.25):
		return '10000000'
	if (num >= 1.25 and num < 1.5):
		return '01000000'
	if (num >= 1.5 and num < 3):
		return '00100000'
	if (num >= 3 and num < 4.0):
		return '00010000'
	if (num >= 4.0 and num < 4.5):
		return '00001000'
	if (num >= 4.5 and num < 5.0):
		return '00000100'
	if (num >= 5.0 and num < 5.75):
		return '00000010'
	return '00000001'

# Sepal_length
#    11 bits
def atributo04(num):
	if num < 0.15:
		return '10000000000'
	if (num >= 0.15 and num < 0.3):
		return '01000000000'
	if (num >= 0.3 and num < 0.5):
		return '00100000000'
	if (num >= 0.5 and num < 1.0):
		return '00010000000'
	if (num >= 1.0 and num < 1.25):
		return '00001000000'
	if (num >= 1.25 and num < 1.35):
		return '00000100000'
	if (num >= 1.35 and num < 1.5):
		return '00000010000'
	if (num >= 1.5 and num < 1.75):
		return '00000001000'
	if (num >= 1.75 and num < 2.0):
		return '00000000100'
	if (num >= 2.0 and num < 2.35):
		return '00000000010'
	return '00000000001'

# Tipo de Iris
#	00 = Iris Setosa
#	01 = Iris Versicolour
#	10 = Iris Virginica
#	11 = None (Destinado a morir)
def tipo(num):
	if ( num == 1):
		return '00'
	if (num == 2):
		return '10'
	return '01'

#######################
#######################
#######  Init  ########
#######################
#######################
def init(genome, **args):
#	print "Im in init"
	_set = []
	size = randrange(1,MAX_SET_SIZE +1)
	for i in xrange(size):
		rule = [rand_choice(('0','1')) for j in xrange(RULE_SIZE)]
		_set = _set + rule
	genome.genomeString = _set
	genome.stringLength = len(_set)

	
def match(chromosome,sample):
	s = long(sample,2)
	c = ''.join(chromosome.genomeString)
	for i in range(0,len(c),RULE_SIZE):
		if ((long(c[i:i+RULE_SIZE],2) & s) == s):
			return True
	return False

#######################
#######################
#######  Fitness ######
#######################
#######################

def fitness(individual):
	score = 0.0
	for sample in TRAINING_SET:
		if ( match(individual,sample) ):
			score += 1.0
	individual.score = score * score
	individual.fitness = score * score
	return score * score

#######################
#######################
#######  GABIL  #######
#######################
#######################

## Crossover
def crossover_gabil(genome, **args):
	sister = None
	brother = None
	gMom = args["mom"]
	gDad = args["dad"]
	
#	print "(1) GMom: %s, GDad: %s " %(gMom, gDad)
	
	if (len(gMom) < len(gDad)):
		gMom , gDad = gDad, gMom
	
#	print "(2) GMom: %s, GDad: %s " %(gMom, gDad)
	
	splitMom = [ rand_randint( 1 , len(gMom) + 1) , rand_randint(1, len(gMom) + 1)]
	
	if (splitMom [1] < splitMom[0] ):
		splitMom[0],splitMom[1] = splitMom[1],splitMom[0] 
		
#	print "LenGMOM: %s, Split mom 0, Split mom 1: %s, %s " %(len(gMom),splitMom[0],splitMom[1])

	s1 = gMom[0:splitMom[0]]
	s2 = gMom[splitMom[0]:splitMom[1]]
	s3 = gMom[splitMom[1]:len(gMom)]
	
	#print "s1 : %s, s2 : %s, s3 : %s " %(s1,s2,s3)
	
	nRulesD = len(gDad) / RULE_SIZE;
	#print nRulesD
	splitDad = [ rand_randint( 1 , nRulesD + 1) , rand_randint(1, nRulesD + 1)]
	
	if (splitDad[0] > splitDad[1] ):
		splitDad[0], splitDad[1] = splitDad[1], splitDad[0]
	
	positionDad = splitMom[0] % RULE_SIZE
	positionDad1 = splitMom[1] % RULE_SIZE
	
	n1 = splitDad[0] + positionDad
	n2 = splitDad[1] + positionDad1

	if (n2 < n1):
		n1,n2 = n2,n1

#	print "len_DAD: %s, Split dad 0, Split dad 1: %s, %s " %(len(gDad),n1,n2)
	d1 = gDad[0:n1]
	d2 = gDad[n1:n2]
	d3 = gDad[n2:len(gDad)]
#	print "d1 : %s, d2 : %s, d3 : %s " %(d1,d2,d3)
	
	sister = gMom.clone()
	sister.resetStats()
	sister.genomeString = s1 + d2 + s3
	sister.stringLength = len(s1 + d2 + s3)
	
	brother = gDad.clone()
	brother.resetStats()
	brother.genomeString = d1 + s2 + d3
	brother.stringLength = len(d1 + s2 + d3)
	#sister = s1 + d2 + s3
	#brother = d1 + s2 + d3
	
	return (sister, brother)

## Mutation

## 		Funcion modificada de la libreria de Pyevolve
##			para la representacion que tenemos.
def G1DBinaryStringMutatorFlip_GABIL(genome, **args):
	if args["pmut"] <= 0.0:
		return 0
	stringLength = len(genome)
	
	mutations = args["pmut"] * (stringLength)
	
	if mutations < 1.0:
		mutations = 0
		for it in xrange(stringLength):
			if Util.randomFlipCoin(args["pmut"]):
				if genome.genomeString[it] == '0': 
					genome.genomeString[it] = '1'
				else: 
					genome.genomeString[it] = '0'
				mutations += 1.0
	else:
		for it in xrange(int(round(mutations))):
			which = rand_randint(0, stringLength - 1)
			if genome.genomeString[which] == '0':
				genome.genomeString[which] = '1'
			else:
				genome.genomeString[which] = '0'
	
	return int(mutations)

##################
##################
#####  Main  #####
##################
##################

if len(sys.argv) != 7:
	response = "Ejecutar como: ./gabil [archivoEntrenamiento] [Seleccion] [Fitness] [TasaMutuacion] [TasaCruce] [archivoPrueba]"
	response += "\n\t seleccion: (1: Ruleta), (2: Mejor de la poblacion) "
	response += "\n\t fitness: (1: Estandar), (2: )"
	response += "\n\t 0.0 <= TasaMutuacion, TasaCruce <= 1.0"
	print response
	sys.exit()

	
#######################
#######################
#####  TRAINING  ######
#######################
#######################

f = open(sys.argv[1],'r')

for line in f:
	l = line.split(" ")
	at = ""
	at = at + atributo01(float(l[0]))
	at = at + atributo02(float(l[1]))
	at = at + atributo03(float(l[2]))
	at = at + atributo04(float(l[3]))
	at = at + tipo(int(l[4]))
	TRAINING_SET = TRAINING_SET + [at]

genome = G1DBinaryString.G1DBinaryString(MAX_SET_SIZE)
genome.initializator.set(init)

## Hay que hacer dos fitness
if(int(sys.argv[2]) == 1):
	genome.evaluator.set(fitness)
else:
	genome.evaluator.set(fitness)

genome.crossover.set(crossover_gabil)
genome.mutator.set(G1DBinaryStringMutatorFlip_GABIL)

## Algoritmo Genetico ##

ga = GSimpleGA.GSimpleGA(genome)
ga.terminationCriteria.set(GSimpleGA.FitnessStatsCriteria)

if(int(sys.argv[2]) == 1):
	ga.selector.set(Selectors.GRouletteWheel)
else: 
	ga.selector.set(Selectors.GRankSelector)

ga.setMutationRate(float(sys.argv[4]))
ga.setCrossoverRate(float(sys.argv[5]))
ga.setGenerations(GENERATIONS)
ga.setPopulationSize(INIT_POP)
ga.evolve(0)

f.close()

#######################
#######################
#####  CLASSIFY  ######
#######################
#######################

f = open(sys.argv[6],'r')
for line in f:
	l = line.split(" ")
	at = ""
	at = at + atributo01(float(l[0]))
	at = at + atributo02(float(l[1]))
	at = at + atributo03(float(l[2]))
	at = at + atributo04(float(l[3]))
	at = at + tipo(int(l[4]))
	SAMPLE_SET = SAMPLE_SET + [at]
	
score = 0.0
for sample in SAMPLE_SET:
	if(match(ga.bestIndividual(),sample)):
		score+=1.0

print "Score: %s, Sample_set: %s" %(score, len(SAMPLE_SET))

print "Porcentaje acertadas: %s" %((float(score)/len(SAMPLE_SET)) * 100)

f.close()