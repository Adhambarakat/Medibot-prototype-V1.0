from tensorflow_datasets.core.features.dataset_feature import Dataset
from tensorflow.python.framework.ops import convert_n_to_tensor
from numpy.lib.shape_base import split
from numpy.core.fromnumeric import var
from numpy.core.memmap import ndarray
from tensorflow_datasets.object_detection.voc import Voc
import tensorflow as tf
import tensorflow_datasets as tfds
import numpy as np
import matplotlib.pyplot as plt
import math as math





dataset  , metadata = tfds.load('horses_or_humans', batch_size = 1, as_supervised = True  , with_info = True) 
training_dataset , test_dataset = dataset['train'] , dataset['test']
num_train_examples = metadata.splits['train'].num_examples



def normalize(images,labels ):
  images = tf.cast(images , tf.float32) # we set every pixel value to a float value
  images /= 255 # we dvide each byte value over 255 to convert it into a bit value
  return(images,labels)
   
training_dataset = training_dataset.map(normalize)

for image in training_dataset.take(num_train_examples):
  break
  image = image.numpy().reshape(28,28)



print(num_train_examples)




model = tf.keras.Sequential([   tf.keras.layers.Flatten(input_shape=( 300, 300, 3)),
                                tf.keras.layers.Dense(128,activation = tf.nn.relu),
                                    tf.keras.layers.Dense(10,activation = tf.nn.softmax)])

model.compile(optimizer='adam' , loss='sparse_categorical_crossentropy', metrics = ('accuracy'), run_eagerly=True)

              
training_dataset = training_dataset.cache().repeat()

test_dataset = test_dataset.cache()




model.fit( training_dataset,steps_per_epoch=math.ceil(num_train_examples) ,epochs=5)
