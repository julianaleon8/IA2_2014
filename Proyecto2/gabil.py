#!/usr/bin/env python

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
from pyevolve import G1DList
from pyevolve import GSimpleGA
from pyevolve import G1DBinaryString
from pyevolve import Initializators
from pyevolve import Util
from pyevolve import Selectors
import sys

TRAINING_SET = []
MAX_SET_SIZE = 4
RULE_SIZE = 32

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
#def init(genome, **args):
"""
	_set = []
	size = randrange(1,MAX_SET_SIZE + 1)
	for i in xrange(size):
		rule = [rand_choice(('0','1')) for j in xrange(RULE_SIZE)]
		_set = _set + rule
	genome.genomeList = _set
"""
def init():
	_rule = ''
	size = randrange(1, MAX_SET_SIZE)
	for i in xrange(size * 32):
		rule = rand_choice(('0','1'))
		_rule = _rule + rule
	return _rule

#######################
#######################
#######  Fitness ######
#######################
#######################
def fitness(individual):
	score = 0
	for sample in TRAINING_SET:
		if ( match(individual,sample) ):
			score += 1
	score = score / len(TRAINING_SET)
	return (score * score)

#######################
#######################
#######  GABIL  #######
#######################
#######################

## Crossover
#def crossover_gabil(genome, **args):
def crossover_gabil(gDad, gMom):

	sister = None
	brother = None
	#gMom = args["mom"]
	#gDad = args["dad"]

	if (len(gMom) < len(gDad)):
		gMom , gDad = gDad, gMom
		
	splitMom = [ rand_randint( 1 , len(gMom) - 1) , rand_randint(1, len(gMom) - 1)]
	
	if (splitMom [1] < splitMom[0] ):
		splitMom[0],splitMom[1] = splitMom[1],splitMom[0] 
		
	print "LenGMOM: %s, Split mom 0, Split mom 1: %s, %s " %(len(gMom),splitMom[0],splitMom[1])

	s1 = gMom[0:splitMom[0]]
	s2 = gMom[splitMom[0]:splitMom[1]]
	s3 = gMom[splitMom[1]:len(gMom)]
	
	print "s1 : %s, s2 : %s, s3 : %s " %(s1,s2,s3)
	
	nRulesD = len(gDad) / RULE_SIZE;
	print nRulesD
	splitDad = [ rand_randint( 1 , nRulesD) , rand_randint(1, nRulesD)]
	
	if (splitDad[0] > splitDad[1] ):
		splitDad[0], splitDad[1] = splitDad[1], splitDad[0]
	
	positionDad = splitMom[0] % RULE_SIZE
	positionDad1 = splitMom[1] % RULE_SIZE
	
	n1 = splitDad[0] + positionDad
	n2 = splitDad[1] + positionDad1

	if (n2 < n1):
		n1,n2 = n2,n1

	print "len_DAD: %s, Split dad 0, Split dad 1: %s, %s " %(len(gDad),n1,n2)
	d1 = gDad[0:n1]
	d2 = gDad[n1:n2]
	d3 = gDad[n2:len(gDad)]
	print "d1 : %s, d2 : %s, d3 : %s " %(d1,d2,d3)

	sister = s1 + d2 + s3
	brother = d1 + s2 + d3
	
	return (sister, brother)

## Mutation


##################
##################
#####  Main  #####
##################
##################

if len(sys.argv) != 2:
	response = "Prueba con: ./gabil.py archivoEntrenamiento"
	print response
	sys.exit()

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

set_m = init()
set_d = init()
print "gMom %s" %(set_m)
print "gDad %s" %(set_d)
sis, bro = crossover_gabil(set_m, set_d )
print "sis : %s (%s), bro : %s(%s)" %(sis,len(sis), bro, len(bro))
#print TRAINING_SET
#genome = G1DBinaryString.G1DBinaryString(MAX_SET_SIZE)
#genome.initializator.set(init)

## Hay que hacer dos fitness
#genome.evaluator.set(fitness)

## COSAS POR DEFINIR --- JULIANA
#	hacer la funcion de mutation y crossover de Gabil y
#		colocar la funcion en los sets:
#genome.crossover.set()
#genome.mutator.set()

f.close()
