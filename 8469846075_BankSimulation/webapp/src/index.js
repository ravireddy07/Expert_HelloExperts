'use strict';

// Famous dependencies
var DOMElement = require('famous/dom-renderables/DOMElement');
var FamousEngine = require('famous/core/FamousEngine');
var Mesh = require('famous/webgl-renderables/Mesh');
var Color = require('famous/utilities/Color');
var Align = require('famous/components/Align');
var Position = require('famous/components/Position');
var Size = require('famous/components/Size');
var Transitionable = require('famous/transitions/Transitionable');

// Protobufjs dependencies
var ProtoBuf = require('protobufjs');
var BankSimulatorState;
ProtoBuf.loadProtoFile("protos/AnimationTrigger.proto", function(err, builder) {
    BankSimulatorState = builder.build("banksimulation.BankSimulatorState");
});

// Boilerplate
FamousEngine.init();

// Initialize with a scene
var scene = FamousEngine.createScene();

var wsSocket;

var events = [];
var tellerCount;

// Create Events

var eventNodes = [];

// Create Teller(s)
var tellerQNodes = [];
var tellerSize;

var firstRun = true;

// Create EventPQ
var eventsPQNode = scene.addChild();

var eventsPQ = new DOMElement(eventsPQNode, {
    content: 'Event Queue',
    properties: {
    	'color': 'white',
    	'border-top': '2px dashed white'
    }
});

eventsPQNode
    .setProportionalSize(1, 0.2)
    .setMountPoint(0, 1)
    .setAlign(0, 1);

// Create Start Button & Clock
var clockNode = scene.addChild();
var startButtonNode = scene.addChild();

var clock = new DOMElement(clockNode, {
    properties: {
    	'color': 'white',
    }
});

var startButton = new DOMElement(startButtonNode, {
	tagName: 'input',
	attributes: {
		'type': 'submit',
		'value': 'Start Simulation'
	},
    
});

clockNode
    .setSizeMode('render', 'render')
    .setMountPoint(0.5, 0.5)
    .setAlign(0.74, 0.35)

startButtonNode
    .setSizeMode('absolute', 'absolute')
    .setAbsoluteSize(130, 50)
    .setMountPoint(0.5, 0.5)
    .setAlign(0.74, 0.45)
    .addUIEvent('click');

startButton.on('click', function() {
    startButton.setAttribute('disabled', true);
    startButton.setAttribute('value', 'Simulation Started');
    startButton._requestUpdate();

    wsSocket = new WebSocket("ws://localhost:1618/ws");
    wsSocket.binaryType = "arraybuffer";
    wsSocket.onopen = function(event) {
    	wsSocket.send("hi");
    }
    wsSocket.onmessage = function(event) {
		var state = BankSimulatorState.decode(event.data);

		console.log(state);

		clock.setContent('<h2>Current Time: ' + state.currentTime + '</h2>');

		if(firstRun) {
			firstRun = false;
			tellerCount = state.tellerCount;
			createTellers();
		}

		switch(state.currentAction) {
			case 0:
				events = state.arrivalEvent;
				loadEvents();

				window.setTimeout(function() {
					wsSocket.send("hi");
				}, 4000);

				break;
			case 1:
				popEvent(state.tellerNum, true);

				window.setTimeout(function() {
					wsSocket.send("hi");
				}, 4000);
				break;
			case 2:
				popEvent(state.tellerNum, false);

				window.setTimeout(function() {
					wsSocket.send("hi");
				}, 4000);
				break;
			case 3:
				exitEvent(state.tellerNum);

				window.setTimeout(function() {
					wsSocket.send("hi");
				}, 4000);
				break;
			case 4:
				advanceEvent(state.tellerNum);

				window.setTimeout(function() {
					wsSocket.send("hi");
				}, 4000);
				break;
			case 5:
				startButton.setAttribute('value', 'Simulation Over');
    			startButton._requestUpdate();
    			wsSocket.close();
    			break;
		}
    	
    }
});

function createTellers() {
	for(var i = 0; i < tellerCount; i++) {
		var tellerNode = scene.addChild();

		var teller = new DOMElement(tellerNode, {
		    content: 'Teller ' + (i+1),
		    properties: {
		    	'color': 'white',
		    	'border': '2px dashed white',
		    	'border-bottom': 'none',
		    	'border-left': 'none'
		    }
		});

		tellerNode
		    .setProportionalSize(0.15, 0.6)
		    .setAlign(0.15*i, 0.2)
		    .addComponent({
		    	onSizeChange: function(size) {
		    		tellerSize = size;
		    	}
		    });
	}

	for(var i = 0; i < tellerCount; i++) {
		tellerQNodes.push([]);
	}
}

function loadEvents() {
	for(var i = 0; i < events.length; i++) {
		var eventNode = scene.addChild();

		var eventElement = new DOMElement(eventNode, {
		    content: '<b>Customer ' + (i+1) + '<br>Arrival Time: ' + events[i].arrivalTime + '<br>'
		    			+ 'Duration: ' + events[i].duration + '</b>',
		    properties: {
		    	'border': '1px solid red',
		    	'color': 'white'
		    }
		});

		eventNode
			.setProportionalSize(0.1, 0.1)
			.setAlign(0, 0.85)
			.addComponent({
				onMount: function(node) {
					this.id = node.addComponent(this);
					this.node = node;
					this.node.eventIndex = i;
					this.node.element = eventElement;

					this.node.shiftLeft = function(tellerNum, direct) {
						this.xPosition = new Transitionable(this.position[0]);

						this.node.requestUpdate(this.id);

						if(this.node.eventIndex == 0) {
							this.xPosition.from(this.position[0]).to(this.position[0] - (tellerCount-tellerNum)*(tellerSize[0] - 2) + (tellerSize[0]-this.size[0])/2, 'linear', 1000, function() {
								var dist, dist2;
								if(direct) {
									dist = 8;
									dist2 = 0;
								} 
								else {
									dist = 6.25;
									dist2 = 1;
								}

								this.yPosition = new Transitionable(this.position[1]);
								this.yPosition.from(this.position[1]).to(this.position[1]-this.size[1]*dist+(tellerQNodes[tellerNum].length - dist2)*this.size[1]*1.5, 'linear', 1000, function() {
									//this.xPosition = null;
									//wsSocket.send("hi");
									tellerQNodes[tellerNum].push(eventNodes.shift());
								}.bind(this));
							}.bind(this));
						} else {
							this.xPosition.from(this.position[0]).to(this.position[0]-this.size[0]-10, 'linear', 1000, function() {
								//wsSocket.send("hi");
							});
						}

					}.bind(this);

					this.node.exit = function() {
						this.xPosition = new Transitionable(this.position[0]);
						this.xPosition.to(this.position[0]+2000, 'linear', 1000);

						this.node.requestUpdate(this.id);

					}.bind(this);

					this.node.advance = function(headOfLine) {
						this.yPosition = new Transitionable(this.position[1]);

						if(headOfLine)
							this.yPosition.to(this.position[1] - this.size[1]*1.75, 'linear', 300);
						else
							this.yPosition.to(this.position[1]-this.size[1]*1.5, 'linear', 300);

						this.node.requestUpdate(this.id);

					}.bind(this);

				},
				onSizeChange: function(size) {
					this.size = size;
					this.node.setPosition((this.size[0]+10)*this.node.eventIndex+(tellerSize[0]+2)*tellerCount, 0, 0);

					this.position = this.node.getPosition();
				},
				onUpdate: function() {
					if(this.xPosition.isActive()) {
						this.node.setPosition(this.xPosition.get());
						this.node.requestUpdateOnNextTick(this.id);
					}
					if(this.yPosition && !this.xPosition.isActive() && this.yPosition.isActive()) {
						this.node.setPosition(this.xPosition.get(), this.yPosition.get());
						this.node.requestUpdateOnNextTick(this.id);
					}
				}
			});

		eventNodes.push(eventNode);
	}
}

function popEvent(tellerNum, direct) {
	eventNodes[0].eventIndex = 0;

	if(direct) {
		eventNodes[0].element.setProperty('border', '1px solid green');
		eventNodes[0].element.setProperty('color', 'rgba(6, 148, 147, 237)');
	}

	for(var i = 0; i < eventNodes.length; i++) {
		eventNodes[i].shiftLeft(tellerNum, direct);
	}
	//eventNodes[0].shiftLeft(tellerNum, direct);
}

function exitEvent(tellerNum) {
	tellerQNodes[tellerNum][0].exit();

	tellerQNodes[tellerNum].shift();
	//eventNodes[0].shiftLeft(tellerNum, direct);
}

function advanceEvent(tellerNum) {
	tellerQNodes[tellerNum][0].element.setProperty('border', '1px solid green');
	tellerQNodes[tellerNum][0].element.setProperty('color', 'rgba(6, 148, 147, 237)');
	tellerQNodes[tellerNum][0].advance(true);

	for(var i = 1; i < tellerQNodes[tellerNum].length; i++)
		tellerQNodes[tellerNum][i].advance(false);

	//tellerQNodes[tellerNum].shift();
	//eventNodes[0].shiftLeft(tellerNum, direct);
}
