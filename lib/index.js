'use strict';

const { EventEmitter } = require('events');
const { Cerberus } = require('bindings')('../build/Release/Cerberus');
const { inherits } = require('util');

inherits(Cerberus, EventEmitter);

exports.Cerberus = Cerberus;